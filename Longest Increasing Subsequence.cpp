#include <vector>

int longestIncreasingSubsequence(int input[], int size)
{
  std::vector<int> sequence;
  sequence.push_back(input[0]);
  int length = 1;
  for(int i = 1; i < size; i++)
  {
      if(input[i] > sequence.back())
      {
          sequence.push_back(input[i]);
          length++;
      }
      else
      {
          int index = lower_bound(sequence.begin(), sequence.end(), input[i]) - sequence.begin();
          sequence[index] = input[i];
      }
  }
    return length;
}
