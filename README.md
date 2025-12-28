# Get_Next_Line

# ##What is this project?
 To create a C function that reads a txt file line by line for a given buffer_size, this function is going to be very useful in future projects;

# ##Must have
   Its necessary to undertsand well the open and read funcions;
   Understand is a static variable;

# ##How to use it
  Clone this repo
  ```bash
  git clone git@github.com:antabord1806/get_next_line.git gnl
  ```
```bash
cd gnl
```
use your main or uncomment the one in get_next_line.c
```bash
cc get_next_line.c
````

# ##My approach

Since the buffer is a static variable, this means that it keeps its value in between calls so we dont have to read the whole document again;

**We read to the buffer, now what?**
- We create a new string **tmp** joining the buffer with **tmp** from the last read, and since we used **ft_strjoin**, we must free the previous alocated string;
```bash
 while (((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
    {
        buffer[bytes_read] = '\0';
        old_tmp = tmp;
        tmp = ft_strjoin(tmp, buffer);
        if (!tmp)
            break;
        free(old_tmp);
```
- This process repeats as long as there is no '\n';
  ```bash
          if (!finding_nl(tmp))
            break;
  ```
**The loop ended**
- Extract a line from the begginging of **tmp** to '\n' including it;
```bash
    while (tmp[tmp_len] && (tmp[tmp_len] != '\n'))
        tmp_len++;
    if (tmp[tmp_len] == '\n')
        tmp_len++;
    char *line = malloc(tmp_len + 1);
    if (!line)
        return NULL;
    for (int i = 0; i < tmp_len; i++)
        line[i] = tmp[i];
    line[tmp_len] = '\0';
```
- Update the buffer by copying the rest of the tmp to the buffer;
  ```bash
      int j = 0;
    while (tmp[tmp_len + j])
    {
        buffer[j] = tmp[tmp_len + j];
        j++;
    }
    buffer[j] = '\0';
    return (line);
  ```
  
