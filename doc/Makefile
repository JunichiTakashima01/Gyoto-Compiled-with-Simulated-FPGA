SHELL=/bin/sh
DOXYGEN=doxygen

all: doxygen.stamp latex.stamp

doxygen.stamp: ../include/*.h ../include/*.h
	$(DOXYGEN) doxyfile
	touch  doxygen.stamp

latex.stamp: ./user_guide/GyotoManual.tex
#	cd user_guide; $(MAKE)
	touch latex.stamp

distclean clean:
	-rm doxygen.stamp latex.stamp
	-rm -fr html xml latex doxygen_sqlite3.db
#	cd user_guide; $(MAKE) clean

%: ;
