import socket

with socket.socket() as s:
    s.bind(('localhost', 8080))
    s.listen(5)
    while True:
        conn, addr = s.accept()
        with conn:
            data = conn.recv(1024)
            print(data.decode('utf-8'))
            conn.sendall(b'HTTP/1.1 200 OK\n\nHello, World!')