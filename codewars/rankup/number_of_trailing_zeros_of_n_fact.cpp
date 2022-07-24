long zeros(long n) {
  // trailing 0s in n! = count of 5s in prime factors of n!
  //                   = floor(n / 5) + floor(n / 25) + floor(n / 125)....
  if(n < 0)
    return -1;
  int count = 0;
  for(int i = 5; n / i >= 1; i *= 5) {
    count += n / i;
  }
  return count;
}