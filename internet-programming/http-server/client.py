import socket
import os

SERVER_HOST = '127.0.0.1'
SERVER_PORT = 8000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((SERVER_HOST, SERVER_PORT))

valid_request = """GET /docssssss/tutorials/linux/shellscripts/howto.html HTTP/1.1\r\n
Host: Linode.com\r\n
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.8) Gecko/20091102 Firefox/3.5.5\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8\r\n
Cache-Control: no-cache\r\n
\r\n
"""

large_line = "X-Large-Header: " + "A" * (10 * 1024 * 1024) + "\r\n"

large_header_request = f"""GET /docssssss/tutorials/linux/shellscripts/howto.html HTTP/1.1\r\n
Host: Linode.com\r\n
{large_line}
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.8) Gecko/20091102 Firefox/3.5.5\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8\r\n
Cache-Control: no-cache\r\n
\r\n\r\n
"""

large_body_request = f"""GET /docssssss/tutorials/linux/shellscripts/howto.html HTTP/1.1\r\n
Host: Linode.com\r\n
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.8) Gecko/20091102 Firefox/3.5.5\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8\r\n
Cache-Control: no-cache\r\n
\r\n\r\n
{large_line}
"""

invalid_characters_request = f"""\x93\xaf\x1b\x8e\x3a\x7f\xc9\xd2\x6a\x5e\x9f\x43\x12\x9d\xe8\xb7\x54\xac\x1f\xdb"""

client_socket.sendall(large_body_request.encode())
client_socket.close()
