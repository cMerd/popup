# popup

A simple popup tool made with raylib.

## Installation
	
All you have to do is clone this git repository and run make.
```bash
	git clone https://github.com/cMerd/popup.git
	make
```	

You can also run the example program with:
```bash
	./build/example
```

## How to use

If you look at [header file](./inc/popup.hpp) for this library you'll notice these:
```cpp
  std::string title;
  std::string context;
  std::map<std::string, std::pair<void (*)(), bool>> actions;
  POPUP_TYPE type;
  bool debug_log;
  Color bg_col;
  Color fg_col;
  Color btn_col1, btn_col2;
```

These are all arguments that you can pass into popup type.
Let's look at them

`title` and `context` are `strings` that will be displayed on popup window.
Example: 
```cpp
	popup_object.title = "Info"; 
	popup_object.context = "Popup window opened.";
```

`actions` is a map storing `string` as key, and a `pair of function and boolean`.
The key is named after actions like: `"ok"`,  `"cancel"`,  `"retry"`, `"yes"` and `"no"`.
Value's first part is `function` that will be executed on button press.
Type of function should be a `void`  with `no parameters`.
Value's second part is a `boolean` which shows if window should be closed after button press.
Example:
```cpp
	void yes_action() {
		std::cout << "YES button is pressed." << std::endl;
	}
	
	popup_object.actions["yes"].first = yes_action;
	popup_object.actions["yes"].second = true; // quit after pressing the button 
```
 
`type` is an `enum` that stores which type of popup this is.
The possible types are: `YES_NO`, `OK_CANCEL`, `OK`, `RETRY_CANCEL`.
Example:
```cpp
	popup_object.type = POPUP_TYPE::YES_NO; // yes and no actions are required!
```

`debug_log` is a `boolean` that shows if raylib logs should be visible.
Example:
```cpp
	popup_object.debug_log = false; // no extra log will be printed.
```

`bg_col`, `fg_col`, `btn_col1`, `btn_col2` are `colors` that will be used by program.
You can find more info on [raylib colors](https://robloach.github.io/raylib-cpp/classraylib_1_1_color.html) here.
But basically, they have `4 parameters`: `Red`, `Green`, `Blue` and `Alpha`.
Example:
```cpp
  popup_object..bg_col = Color{33, 33, 33, 255};
  popup_object..fg_col = Color{200, 200, 200, 255};
  popup_object..btn_col1 = Color{44, 44, 44, 255};
  popup_object..btn_col2 = Color{66, 66, 66, 255};
```

To run or enable the popup all you have to do is to execute the `run` method.
Note that `program will stop` until popup window is closed.
Example:
```cpp
	popup_object.run();
```

### Thanks for visiting!
