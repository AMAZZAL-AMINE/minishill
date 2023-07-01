#include "../minishell.h"

int is_cmd_redirected(char *cmd) {
  if (str_cmp(cmd, ">") || str_cmp(cmd, ">>")
    || str_cmp(cmd, "<") || str_cmp(cmd, "<<")) {
      return 1;
  }
  return 0;
}
