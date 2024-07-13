build:
	@g++ -std=c++17 -O2 calcAvgFitness.cpp -lm -Wall -o exe/avgfit

run: build
	@for /l %%i in (1,1,8) do ( \
			.\exe\avgfit %%i > out\%%i.txt \
	)

buildv:
	@g++ -std=c++17 -O2 vel.cpp -lm -Wall -o exe/vel

runv: buildv
	@for /l %%i in (1,1,3) do ( \
			.\exe\vel %%i > vel-out\%%i.txt \
	)

builde:
	@g++ -std=c++17 -O2 en.cpp -lm -Wall -o exe/en

rune: builde
	@for /l %%i in (1,1,3) do ( \
			.\exe\en %%i > en-out\%%i.txt \
	)