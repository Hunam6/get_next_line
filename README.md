<div align="center">
  <h1>get_next_line</h1>
  <b>Indispensable utility to read a file</b>
</div>

## 🛠️ Installation

Compile your project with `get_next_line.c` and `get_next_line_utils.c`.
Include `get_next_line.h` in your file.

## 📚 Usage

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	if (ac != 2)
		return(printf("Usage: ./gnl <file>\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Failed to open the file.\n"));
	while (42)
	{
		char *line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
	}
	if (close(fd) == -1)
		return (printf("Failed to close the file.\n"));
}
```
