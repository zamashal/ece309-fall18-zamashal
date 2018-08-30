
all:
	@make -C lib  all
	@make -C tests all

tests: all
	@make -C tests test

clean:
	@make -C lib clean
	@make -C tests clean
