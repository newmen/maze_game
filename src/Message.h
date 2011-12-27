/*
 * Message.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

namespace MazeGame {

class Message {
public:
	Message(const char *text);
	Message(const Message &other);
	virtual ~Message();

	Message operator=(const Message &other);

	const char* text() const { return _text; }

private:
	char *_text;
};

}

#endif /* MESSAGE_H_ */
