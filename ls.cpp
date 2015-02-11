/* File system */
#include <dirent.h>

/* io */
#include <stdio.h>

void list_dir(const char *dir_name)
{
  DIR *directory;
  struct dirent *directory_entry;

  directory = opendir(dir_name);
  if (directory == NULL)
    {
      printf("%s doesn't exists.\n", dir_name);
      return;
    }

  while ((directory_entry = readdir(directory)) != NULL)
    {
      printf("%s\n", directory_entry->d_name);
    }

  closedir(directory);
}


int main(int argc, char *argv[])
{
  if (argc == 1)
    {
      list_dir(".");
    }
  else
    {
      int i;
      for (i = 1; i < argc; i++)
        {
          list_dir(argv[i]);
        }
    }
}
