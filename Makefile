all: build run
build:
	cc -o shader_renderer shader_renderer.c -lraylib -lm -lpthread -ldl -lrt -lX11
run:
	./shader_renderer
