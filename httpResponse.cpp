#include "httpResponse.hpp"

httpResponse::httpResponse()
{
	// constructor
	this->_statusCode = 0;
	this->_reasonPhrase = "";
	this->_version = "HTTP/1.1";
	this->_headers = std::map<std::string, std::string>();
	this->_body = "";
}

httpResponse::~httpResponse()
{
	// destructor
}

void httpResponse::setStatusCode(int code)
{
	// set the status code
	std::map<std::string, std::string> codePhrase;
	codePhrase.insert(std::make_pair("200", "OK"));
	codePhrase.insert(std::make_pair("201", "Created"));
	codePhrase.insert(std::make_pair("202", "Accepted"));
	codePhrase.insert(std::make_pair("204", "No Content"));
	codePhrase.insert(std::make_pair("400", "Bad Request"));
	codePhrase.insert(std::make_pair("401", "Unauthorized"));
	codePhrase.insert(std::make_pair("403", "Forbidden"));
	codePhrase.insert(std::make_pair("404", "Not Found"));
	codePhrase.insert(std::make_pair("405", "Method Not Allowed"));
	codePhrase.insert(std::make_pair("408", "Request Timeout"));
	codePhrase.insert(std::make_pair("413", "Payload Too Large"));
	codePhrase.insert(std::make_pair("414", "URI Too Long"));
	codePhrase.insert(std::make_pair("500", "Internal Server Error"));
	codePhrase.insert(std::make_pair("501", "Not Implemented"));
	codePhrase.insert(std::make_pair("502", "Bad Gateway"));
	codePhrase.insert(std::make_pair("503", "Service Unavailable"));
	codePhrase.insert(std::make_pair("505", "HTTP Version Not Supported"));

	this->_statusCode = code;
	std::string codeStr = intToString(code);
	this->_reasonPhrase = codePhrase[codeStr];
	if (this->_statusCode >= 300)
	{
		this-> _body = "<html><head><title>" + codeStr + " "
			+ this->_reasonPhrase + "</title></head><body><h1>" + codeStr
			+ " " + this->_reasonPhrase + "</h1></body></html>";
	}
}

int httpResponse::getStatusCode() const
{
	// get the status code
	return this->_statusCode;
}

void httpResponse::setHeaders(const std::map<std::string, std::string> &responseHeaders)
{
	// set the headers
	this->_headers = responseHeaders;
}

void httpResponse::setBody(std::string &responseBody)
{
	// set the body
	this->_body = responseBody;
}

std::string httpResponse::getResponse() const
{
	std::string codeStr = intToString(_statusCode);
	// get the response
	std::string response = this->_version + " " + codeStr + " " + this->_reasonPhrase + "\r\n";
	// confirm if we want keep this or not for the moment
	if (this->_statusCode >= 300)
	{
		std::string contentLeangthStr = intToString(this->_body.size());
		response += "Content-Length: " + contentLeangthStr + "\r\n";
		response += "Content-Type: text/html\r\n";
	}
	else
	{
		for (std::map<std::string, std::string>::const_iterator it = this->_headers.begin(); it != this->_headers.end(); ++it)
		{
			response += it->first + ": " + it->second + "\r\n";
		}
	}
	response += "\r\n";
	response += this->_body;
	return response;
}

std::string intToString(int num){
	std::stringstream ss;
	ss << num;
	return (ss.str());
}
