// (i) Function to check if four numbers are in ascending sequence
bool in_sequence(int a, int b, int c, int d) {
  if (a < b && b < c && c < d) {
      return true;
  }
  return false;
}

// (ii) Function to check if first number is square root of others
bool source(int a, int b, int c) 
{
  if (a * a == b && a * a == c) {
      return true;
  }
  return false;
}

// (iii) Function to check if character is decimal digit
bool number(char ch1, char ch2) 
{
  if (ch1 >= '0' && ch1 <= '9') {
      return true;
  }
  return false;
}

// (iv) Function to check if character is uppercase letter
bool is_uppercase(char ch1, char ch2) 
{
  if (ch1 >= 'A' && ch1 <= 'Z') {
      return true;
  }
  return false;
}

// (v) Function to multiply three numbers
int multiplyNumbers(int x, int y, int z) 
{
  return x * y * z;
}