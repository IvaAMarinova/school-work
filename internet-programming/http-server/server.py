import socket
import sys
import errno
from parser import parser

MAX_SIZE = 10 * 1024 * 1024  # 10MB

SERVER_HOST = '0.0.0.0'
SERVER_PORT = 8000

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((SERVER_HOST, SERVER_PORT))
server_socket.listen(5)
print('Listening on port %s ...' % SERVER_PORT)

def is_valid_header(line):
    return ':' in line and len(line.split(':', 1)) == 2

try:
    while True:
        try:
            client_connection, client_address = server_socket.accept()
            print(f"Connection from {client_address}")

            request_data = b''
            header_size = 0
            body_size = 0
            headers_done = False

            while True:
                try:
                    chunk = client_connection.recv(1024)
                    if not chunk:
                        break

                    request_data += chunk
                    chunk_length = len(chunk)

                    if not headers_done:
                        header_size += chunk_length

                        if header_size > MAX_SIZE:
                            raise ValueError("Header size exceeds 10MB")

                        if b"\r\n\r\n" in chunk:
                            headers_done = True

                            end_of_headers_index = chunk.index(b"\r\n\r\n") + 4
                            body_size += (chunk_length - end_of_headers_index)
                           
                            if body_size > MAX_SIZE:
                                raise ValueError("Body size exceeds 10MB")
                    else:
                        body_size += chunk_length
                        if body_size > MAX_SIZE:
                            raise ValueError("Body size exceeds 10MB")

                except socket.error as e:
                    if e.errno == errno.EWOULDBLOCK or e.errno == errno.EAGAIN:
                        continue
                    else:
                        raise

            if not request_data:
                print("No request data received.")
                client_connection.close()
                continue

            request = request_data.decode()

            try:
                parser_result = parser(request)
                print("Method: ", parser_result["method"])
                print("Headers: ", parser_result["headers"])

                if "body" in parser_result:
                    print("Body: ", parser_result["body"])
                print("//////////////////////////////////////////////////////")
            except ValueError as e:
                print(f"Invalid request - {e}")
                client_connection.close()
                continue

            client_connection.close()

        except ValueError as size_error:
            print(f"Error: {size_error}. Closing server.")
            break

        except Exception as e:
            print(f"Error handling client connection: {e}")

except Exception as e:
    print(f"Server shut down due to an error: {e}")

finally:
    server_socket.close()
    print("Server shut down successfully")
