subdir := attack demo
suball := $(addsuffix .all, $(subdir))
subsrc := $(patsubst %,%/*.c,$(subdir))
subclean := $(addsuffix .clean, $(subdir))

include-dir := include
include-header := $(patsubst %,%/*.h, $(include-dir))

.PHONY: all clean $(subdir)

all: $(suball)

$(subdir): $(subsrc)
	$(MAKE) -C $@

$(suball): $(subdir)

clean: $(subclean)

$(subclean):
	$(MAKE) -C $(patsubst %.clean,%, $@) clean
