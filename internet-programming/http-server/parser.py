def parser(request):
    request_lines = request.split("\r\n")
    request_sorted = {"method": (), "headers": {}, "body": ""}

    try:
        method, path, version = request_lines[0].split()
    except ValueError:
        raise ValueError("Invalid request line: Could not parse method, path, and version")

    valid_methods = ["GET", "POST", "PATCH", "PUT", "DELETE"]
    if method not in valid_methods:
        raise ValueError("Invalid method in request")

    request_sorted["method"] = (method)
    
    if not version.startswith("HTTP/"):
        raise ValueError("Invalid version format in request")
    
    header_section = True
    for line in request_lines[1:]:
        line = line.strip()

        if line == "" and header_section:
            header_section = False
            continue

        if header_section:
            if ':' not in line or len(line.split(':', 1)) != 2:
                raise ValueError(f"Invalid header line in request: {line}")

            key, data = line.split(':', 1)
            key = key.strip()
            data = data.strip()
            
            if not key or not data:
                raise ValueError(f"Invalid structure in request (missing key or data): {line}")
            else:
                request_sorted["headers"][key] = data
        else:
            request_sorted["body"] += line + "\n"

    return request_sorted

def are_valid_request_characters(string):
    allowed_characters = set("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ :;.,\\/\"'?!(){}[]@<>=-+*#$&`|~^%")
    return all(char in allowed_characters for char in string)


request = """GET /docssssss/tutorials/linux/shellscripts/howto.html HTTP/1.1\r\n
Host: Linode.com\r\n
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.8) Gecko/20091102 Firefox/3.5.5\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8\r\n
Cache-Control: no-cache\r\n
\r\n"""

request2 = """POST /api/2.2/auth/signin HTTP/1.1\r\n
HOST: my-server\r\n
Content-Type:application/json\r\n
Accept:application/json\r\n
\r\n
{\r\n
  "credentials": {\r\n
    "name": "administrator",\r\n
    "password": "passw0rd",\r\n
    "site": {\r\n
      "contentUrl": ""\r\n
    }\r\n
  }\r\n
}\r\n
"""

parser(request2)
