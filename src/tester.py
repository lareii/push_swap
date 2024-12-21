import subprocess
import random

INT_MIN = -2147483648
INT_MAX = 2147483647

def test_random_numbers(count):
	flag = True

	for i in range(count):
		rand_list = ' '.join(map(str, random.sample(range(INT_MIN, INT_MAX), 100)))
		cmd = f"./push_swap {rand_list} | ./checker_linux {rand_list}"
		result = subprocess.run(cmd, shell=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		if result.stdout.strip() != "OK":
			print(rand_list)
			flag = False
			break
	print("OK" if flag else "KO")

def test_limits():
	cmd = f"./push_swap {INT_MIN} {INT_MAX} | ./checker_linux {INT_MIN} {INT_MAX}"
	result = subprocess.run(cmd, shell=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	print("KO" if result.stdout.strip() != "OK" else "OK")

def test_overflow():
	cmd = f"./push_swap {INT_MIN - 1} {INT_MAX + 1} | ./checker_linux {INT_MIN - 1} {INT_MAX + 1}"
	result = subprocess.run(cmd, shell=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	print("OK" if result.stderr.strip() else "KO")

test_overflow()