import aiohttp
import asyncio
import time

async def main():

	session = aiohttp.ClientSession(connector=aiohttp.TCPConnector(ssl=False))
	res = await session.get("http://127.0.0.1:6001")

	print(res.text)

	await session.close()

start = time.time()

if __name__ == "__main__":
	asyncio.run(main())
	asyncio.sleep(5)

finish = time.time()

print(finish - start)