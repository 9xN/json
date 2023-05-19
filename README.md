# json

This is a simple JSON library implemented in C that allows you to create JSON objects and convert them to formatted strings. It provides basic functionality for adding key-value pairs to a JSON object and obtaining the JSON representation as a string.

## Usage

1. Clone the repository to your local machine:

```
git clone https://github.com/9xN/json.git
```

2. Include the `json.h` header file in your C program:

```c
#include "json.h"
```

3. Create a `jsonObject` instance and initialize it:

```c
jsonObject myJson;
myJson.count = 0;
```

4. Add key-value pairs to the JSON object using the `json_add_pair` function:

```c
json_add_pair(&myJson, "key1", "value1");
json_add_pair(&myJson, "key2", "value2");
// Add more key-value pairs as needed
```

5. Convert the JSON object to a formatted string using the `json_to_string` function:

```c
char *jsonString = json_to_string(&myJson);
```

6. Use the resulting `jsonString` as needed, such as in web requests or other contexts.

7. Don't forget to free the memory allocated for the JSON string when you're done using it:

```c
free(jsonString);
```

## Example

Here's an example program that demonstrates the usage of the JSON library:

```c
#include <stdio.h>
#include <stdlib.h>
#include "json.h"

int main() {
    jsonObject myJson;
    myJson.count = 0;

    json_add_pair(&myJson, "name", "John");
    json_add_pair(&myJson, "age", "25");
    json_add_pair(&myJson, "city", "New York");

    char *jsonString = json_to_string(&myJson);
    if (jsonString != NULL) {
        printf("JSON string: %s\n", jsonString);
        free(jsonString);
    }

    return 0;
}
```

## Limitations

- This JSON library has a maximum JSON size limit of 4096 characters. If you need to handle larger JSON objects, you may need to modify the library accordingly.
- This library provides basic functionality for creating JSON objects and converting them to strings. It does not include advanced features like parsing JSON strings or handling nested objects.

## Contributions

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## License

This JSON library is open source and distributed under the [GNU Affero General Public License](LICENSE).