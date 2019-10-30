from random import randint

def thanos_sort(array):
	while not is_sorted(array):
		target_length = int(len(array)/2)
		while len(array) > target_length:
			del array[randint(0, len(array)-1)]
	return array
	
def is_sorted(array):
	for i in range(len(array)-1):
		if array[i] > array[i+1]:
			return False
	return True
