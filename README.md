<p align = "center">Webserv</p>
<p align = "center"> <a href = https://github.com/Hotaruban><img webserv = "webserv" src = "./webservm.png"></a></p>

Team members:
- <a href = https://github.com/PoissonC>Yu</a> (intra: <a href = https://profile.intra.42.fr/users/ychen>ychen</a>)
- <a href = https://github.com/kobewinona>Dima</a> (intra: <a href = https://profile.intra.42.fr/users/dklimkin>dklimkin</a>)
- <a href = https://github.com/Hotaruban>Jeremy</a> (intra: <a href = https://profile.intra.42.fr/users/jhurpy>jhurpy</a>)

### The "Webserv" project at 42 school challenges participants to build a simple HTTP server from scratch, following the HTTP/1.1 protocol. This project provides an opportunity to explore network programming, socket management, and web server functionality in a real-world context.

### Key Points:

**HTTP Protocol Implementation**: Participants must create a server that communicates using the HTTP/1.1 protocol. This involves handling HTTP methods such as GET, POST, and DELETE, as well as understanding headers, status codes, and request parsing.

**Socket Programming**: The project focuses on the fundamentals of network programming, requiring participants to establish and manage sockets for client-server communication. This includes handling multiple clients simultaneously using the epoll system call for efficient I/O multiplexing.

**CGI (Common Gateway Interface) Integration**: Webserv must support the execution of external programs through CGI scripts. This enables dynamic content generation and requires understanding how to interact with external processes securely and efficiently.

**Request Handling and Response**: Building the server involves setting up a request-response cycle. The server parses incoming client requests, processes them according to the HTTP method and resource requested, and sends back an appropriate response.

**Configuration File Parsing**: Similar to how NGINX or Apache servers operate, participants are tasked with creating a configuration file that allows customization of the server’s behavior (e.g., port, root directory, error pages, etc.). The configuration parser should handle errors gracefully and adapt to different setups.

**Concurrent Client Handling**: Managing multiple client connections efficiently is a crucial aspect of the project. Webserv must be capable of handling concurrent requests without crashing, ensuring robustness and scalability.

**Methodology**:
The project encourages a modular approach, starting with basic socket setup and HTTP request parsing, followed by response handling and CGI integration. Special emphasis is placed on performance, error handling, and adhering to the HTTP/1.1 protocol.

**Assessment**:
Evaluation is based on the correct implementation of HTTP/1.1 features, effective management of client connections, and proper handling of CGI scripts. The ability to create a robust, scalable, and well-documented server with a flexible configuration is crucial for a successful project submission.

The "Webserv" project provides participants with a solid foundation in network programming and web server development, preparing them for more complex web-based systems and real-world server management.
