import asyncio
#import time
a = 2
b = 8

async def async_fun(a, b):

	print("multiplication %d", a*b)
	return 0

async def async_sleep(a, b):

	await asyncio.sleep(4)

	print("addition %d", a+b)
	return 0

async def function3():

	print("hello")
	return 0


async def main():

	await asyncio.gather(async_sleep(a, b), function3(), async_fun(a, b))


asyncio.run(main())