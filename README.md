# cpp_logger

*A C++98 logging library for terminal applications created by **guillsan**
<br>A wrapper around `std::cout` and `std::cerr` with support for colors, text formatting, and stream-style logging.*

## Installation (other methods listed at the end)

Fetch the files (Log.hpp, Log.tpp & Log.cpp):
```bash
mkdir -p inc src && \
curl -L https://raw.githubusercontent.com/Guirie92/cpp_logger/master/inc/Log.hpp -o inc/Log.hpp && \
curl -L https://raw.githubusercontent.com/Guirie92/cpp_logger/master/inc/Log.tpp -o inc/Log.tpp && \
curl -L https://raw.githubusercontent.com/Guirie92/cpp_logger/master/src/Log.cpp -o src/Log.cpp
```

Add the logger's source file to your Makefile.

For example:
```make
SRC += src/Log.cpp
```

---

## Features

- Stream-style interface (`<<`)
- Colored output
- Warning and error streams
- Text formatting (bold, italic, underline)
- Optional flags (`NO_ENDL`, `FLUSH`, etc.)

## Requirements

- C++98 compatible
- A compiler with ANSI terminal color support
- No external dependencies

---

## Usage

```cpp
#include "log.hpp"

int main()
{
	Log::print() << "Hello world!";

	// Printed in yellow and prefixed with "[WARNING]: "
	Log::warn()  << "careful!";

	// Printed in red and prefixed with "[ERROR]: "
	Log::error() << "something went wrong";

	Log::print(Log::GRN, Log::BOLD) 
		<< "I'm printed in Green color with Bold font";

	Log::print(Log::BOLD | Log::ITALIC | Log::UNDERLINE) 
		<< "I'm bold, with italic style and underline";

	// Flags and colors can be freely combined:
	Log::print(Log::BOLD | Log::ITALIC | Log::UNDERLINE) 
		<< "I'm bold, with italic style and underline\n"
		<< Log::RST_BOLD << "I'm not bold anymore, but I'm underline + italic\n"
		<< Log::RST_UNDERLINE << "I'm just italic now\n"
		<< Log::NONE << "I'm a completely DEFAULT log message\n"
		<< Log::CYAN << "I'm a cyan-color message";

	int coins = 42;
	Log::print(Log::RED, Log::BOLD | Log::NO_ENDL)
		<< "I'm a red, bold text\n"
		<< "You have " << coins << " coins\n"
		<< "I don't end with a new line because of the NO_ENDL flag";

	Log::print() << ", so I'm completely appended to the previous message";

	return 0;
}
```

### Example output:
<p align="left">
    <img src="https://i.imgur.com/xoTYV3H.png" width="800" alt="cpp_logger demo">
</p>


## API

```cpp
Log::print(color, flags)
Log::warn(color, flags)
Log::error(color, flags)
```
(parameters are completely optional)

Colors:

- `DFL`
- `RED`
- `YLW`
- `GRN`
- `BLUE`
- `MAG`
- `CYAN`

Flags:

- `NONE`
- `NO_ENDL`
- `FLUSH`
- `BOLD`
- `ITALIC`
- `UNDERLINE`
- `RST_BOLD`
- `RST_ITALIC`
- `RST_UNDERLINE`

## Other Installation Methods
Clone the repository into your project's external folder (it creates one if it doesn't exist):

### Step #1

#### Option 1 - Raw Files (in external):
```bash
mkdir -p external/cpp_logger/inc external/cpp_logger/src && \
curl -L https://raw.githubusercontent.com/Guirie92/cpp_logger/master/inc/Log.hpp -o external/cpp_logger/inc/Log.hpp && \
curl -L https://raw.githubusercontent.com/Guirie92/cpp_logger/master/inc/Log.tpp -o external/cpp_logger/inc/Log.tpp && \
curl -L https://raw.githubusercontent.com/Guirie92/cpp_logger/master/src/Log.cpp -o external/cpp_logger/src/Log.cpp
```

#### Option 2 - git submodule:
```bash
git submodule add https://github.com/Guirie92/cpp_logger.git external/cpp_logger
```

#### Option 3 - git repo:
```bash
git clone https://github.com/Guirie92/cpp_logger.git external/cpp_logger
```

### Step #2
Add the logger's include directory and source file to your Makefile.

For example:
```make
CPPFLAGS += -I external/cpp_logger/inc
SRC += external/cpp_logger/src/Log.cpp
```

(If your project uses `CFLAGS`, `SRCS`, or different variable names, adjust the names accordingly)

Your project should look similar to:
```
project/
├── external/
│   └── cpp_logger/
├── src/
├── inc/
└── Makefile
```