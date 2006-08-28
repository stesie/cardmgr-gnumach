all:
install: $(install_files)
	for A in $(install_scripts); do \
	  install --mode=0755 $$A /etc/pcmcia/; \
	done

	@echo "installing *.opts files (please edit them to fit your needs) ..."
	@echo
	for A in $(install_files); do \
	  if [ -e /etc/pcmcia/$$A ]; then \
	    echo "refusing to overwrite /etc/pcmcia/$$A."; \
	  else \
	    install --mode=0644 $$A /etc/pcmcia/; \
	  fi; \
	done

	@if [ -e /etc/pcmcia.conf ]; then \
	  echo "refusing to overwrite /etc/pcmcia.conf."; \
	else \
	  install --mode=0644 pcmcia.conf /etc/; \
	fi

	@echo
	install --mode=0755 rc.pcmcia /etc/init.d/pcmcia
	@echo "do not forget to add a link to \`/etc/init.d/pcmcia' in \`/etc/rc2.d'!"
	
install_scripts = \
	ftl \
	ide \
	ieee1394 \
	memory \
	network \
	parport \
	scsi \
	serial \
	wireless


install_files = \
	config \
	config.opts \
	ftl.opts \
	ide.opts \
	ieee1394.opts \
	memory.opts \
	network.opts \
	parport.opts \
	scsi.opts \
	serial.opts \
	shared \
	wireless.opts

cis_files = \
	cis/3CCFEM556.cis \
	cis/3CCFEM556.dat \
	cis/3CXEM556.cis \
	cis/3CXEM556.dat \
	cis/COMpad2.cis \
	cis/COMpad2.dat \
	cis/COMpad4.cis \
	cis/COMpad4.dat \
	cis/DP83903.cis \
	cis/DP83903.dat \
	cis/E-CARD.cis \
	cis/E-CARD.dat \
	cis/LA-PCM.cis \
	cis/LA-PCM.dat \
	cis/MT5634ZLX.cis \
	cis/MT5634ZLX.dat \
	cis/Makefile \
	cis/NE2K.cis \
	cis/NE2K.dat \
	cis/PCMLM28.cis \
	cis/PCMLM28.dat \
	cis/PE-200.cis \
	cis/PE-200.dat \
	cis/PE520.cis \
	cis/PE520.dat \
	cis/RS-COM-2P.cis \
	cis/RS-COM-2P.dat \
	cis/tamarack.cis \
	cis/tamarack.dat
