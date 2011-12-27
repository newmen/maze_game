/*
 * Message.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Message.h"
#include <cstring>

namespace MazeGame {

Message::Message(const char *text) {
	int length = strlen(text);
	_text = new char[length + 1];
	strcpy(_text, text);
}

Message::Message(const Message &other) {
	int length = strlen(other._text);
	_text = new char[length + 1];
	strcpy(_text, other._text);
}

Message::~Message() {
	delete [] _text;
}

Message Message::operator=(const Message &other) {
	delete [] _text;
	int length = strlen(other._text);
	_text = new char[length + 1];
	strcpy(_text, other._text);
}

}
