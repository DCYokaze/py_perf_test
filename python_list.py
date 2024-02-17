import pytest
import time
@pytest.mark.benchmark(
    group="group-name",
    min_time=0.1,
    max_time=0.5,
    min_rounds=5,
    timer=time.time,
    disable_gc=True,
    warmup=False
)
# def test_remove_from_list_last(input1, benchmark):
#   benchmark(remove_from_list_last, input1)
# @pytest.mark.some_mark
def test_remove_from_list_last(benchmark):
  result = benchmark(remove_from_list_last )
  # print(f"result is_______________------------ {result}")

def test_remove_from_list_first(benchmark):
  result = benchmark(remove_from_list_first )
  # print(f"result is_______________------------ {result}")
  
def remove_from_list_last(n=10**4):
  aList = [0]*n
  for i in reversed(range(n)):
    aList.pop(-1)

def remove_from_list_first(n=10**4):
  aList = [0]*n
  for i in range(n):
    aList.pop(0)


if __name__ == "__main__":
  print("test1")
  pytest.main()
  # remove_from_list_last(10**2)
  # test_f1()
  pass
  # main()