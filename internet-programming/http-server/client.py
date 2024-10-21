import socket

SERVER_HOST = '127.0.0.1'
SERVER_PORT = 8000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((SERVER_HOST, SERVER_PORT))

request = """GET /docssssss/tutorials/linux/shellscripts/howto.html HTTP/1.1\r\n
Host: Linode.com\r\n
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.8) Gecko/20091102 Firefox/3.5.5\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8\r\n
Cache-Control: no-cache\r\n
\r\n
"""

client_socket.sendall(request.encode())
client_socket.close()
