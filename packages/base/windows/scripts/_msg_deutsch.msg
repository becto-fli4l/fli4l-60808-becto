; -------------------------------------------------------------------------
; language constants (german)                                  __FLI4LVER__
;
; Creation: lanspezi 2005-04-14
; $Id$
; -------------------------------------------------------------------------

[Global]
MSG_LINE===================================================================
MSG_BTN_close=Schlie�en
MSG_msgbox_error=Fehler
MSG_msgbox_warn=Warnung
MSG_msgbox_info=Info
MSG_errorfilelog=Die LOG-Datei kann nicht ge�ffnet werden!
MSG_errorfilelogerror=Die Fehler-LOG-Datei kann nicht ge�ffnet werden!
MSG_finished=abgeschlossen.
MSG_cancel=abgebrochen.
MSG_00_scpstart=�bertrage die Dateien per SCP zum Router ...
MSG_00_scpend=SCP-�bertragung abgeschlossen.
MSG_00_scpend2=Starten Sie nun Ihren fli4l-Router neu.
MSG_00_pass=Passwort f�r die SCP-�bertragung
MSG_00_usebasepass=Passwort aus 'base.txt' verwenden?
MSG_00_scpenterpass=Passwort f�r die SCP-�bertragung eingeben f�r den Host:
MSG_00_scpcancel=Die SCP-�bertragung wurde auf Benutzeranforderung abgebrochen.
MSG_00_scperror1=Bei der SCP-�bertragung ist ein Fehler aufgetreten!
MSG_00_scperror2=Bitte �berpr�fen Sie alle SSH-Parameter und den sshd auf dem Router.
MSG_00_changesshkey=SSH-Keyfile ausw�hlen
MSG_00_plinkaskreboot=M�chten Sie den Router jetzt neu starten?
MSG_00_plinksentreboot=Der Befehl zum Neustart wurde an den Router gesendet.
MSG_00_askreboot=fli4l - Router Neustart

[mkfli4l]
MSG_01_build_abort=Der Build-Prozess wurde auf Benutzeranforderung abgebrochen.
MSG_01_build_error=Der Build-Prozess wurde aufgrund eines Fehlers abgebrochen!
MSG_01_no_boot_type=Ung�ltiger Wert f�r die Variable BOOT_TYPE!

[parse_cmd]
MSG_02_start=__FLI4LVER__ - Build Prozess
MSG_02_noconfdir=Im Verzeichnis mit der fli4l-Konfiguration existiert keine base.txt!
MSG_02_useconfig=Verwende die Konfiguration aus dem Verzeichnis '
MSG_02_undefboottype=Die Variable BOOT_TYPE ist nicht definiert! Bitte Konfigurations-Dateien im korrekten Format benutzen.
MSG_02_migrateconfig=Migriere mkfli4l.conf zu mkfli4l.txt...

[parse_mkfli4l_conf]
MSG_03_readcheck_buildenv=Einlesen und Pr�fen des Build-Environments '
MSG_03_nologfile=Die mkfli4l_conf-Log-Datei kann nicht ge�ffnet werden!

[mkopt]
MSG_04_start=Erzeugen der fli4l-Dateien ...
MSG_04_confdir=Benutze die Konfiguration aus dem Verzeichnis '
MSG_04_builddir=Erzeuge die fli4l-Dateien im Verzeichnis '
MSG_04_readcheckconf=Einlesen und Pr�fen der Konfiguration, Erzeugen des rootfs- und opt-Archives ...
MSG_04_generating_md5sums=md5-Pr�fsummen generieren ...
MSG_04_finished=Erzeugung der fli4l-Dateien abgeschlossen.
MSG_04_nologfile=Die mkfli4l-Log-Datei kann nicht ge�ffnet werden!
MSG_04_msgboxerror=Fehler in den fli4l-Konfigurationsdateien!

[mkfloppy]
MSG_05_start=Erstellen der fli4l-Diskette(n) ...
MSG_05_insertfloppy=Bitte formatierte Diskette einlegen.
MSG_05_bootdisk=(diese wird Ihre BOOT_DISK)
MSG_05_startcopy=Bitte auf OK klicken oder RETURN dr�cken um das Kopieren der Dateien auf die Diskette zu starten.
MSG_05_copysyslinux=Kopiere syslinux.cfg ...
MSG_05_writesystem=Schreibe System-Dateien ...
MSG_05_copykernel=Kopiere kernel ...
MSG_05_copyrootfstgz=Kopiere rootfs.img ...
MSG_05_copyrootfsbz2=Kopiere rootfs.bz2 ...
MSG_05_copyrccfg=Kopiere rc.cfg ...
MSG_05_copyopttarbz2=Kopiere opt.img ...
MSG_05_bootdisk2= (BOOT_DISK)
MSG_05_optdisk= (OPT_DISK)
MSG_05_secfloppy1=Bitte die erste Diskette entnehmen (BOOT_DISK).
MSG_05_secfloppy2=Bitte formatierte Diskette einlegen und RETURN dr�cken oder OK klicken.
MSG_05_secfloppy3=(das ist die OPT_DISK)
MSG_05_floppynowrite1=Beim Schreiben der Datei '
MSG_05_floppynowrite2=ist ein Fehler aufgetreten!
MSG_05_floppynospace=Auf der Diskette ist nicht gen�gend Speicher f�r die Build Dateien.
MSG_05_bootflnospace=Auf der BOOT-Diskette ist nicht gen�gend Speicher f�r die Build Dateien.
MSG_05_cancel=Erstellung der Diskette(n) auf Benutzeranforderung abgebrochen.
MSG_05_error=Fehler beim Erstellen der Diskette(n)!
MSG_05_finish1=Erstellung der Diskette(n) abgeschlossen.
MSG_05_finish2=Starten Sie nun Ihren fli4l-Router mit der/den neuen Diskette(n).
MSG_05_filesonfloppy=Auf der Diskette befinden sich Dateien. L�schen?
MSG_05_usefloppy=Soll diese Diskette trotzdem benutzt werden?
MSG_05_nofloppy=Keine Diskette im Laufwerk!
MSG_05_nofloppyW9x=Keine Diskette im Laufwerk oder Diskette ist nicht formatiert!
MSG_05_calculatespace=Ben�tigten Platz berechnen ...
MSG_05_requiredspace1=Ben�tigter Platz:
MSG_05_requiredspace2=Bytes.
MSG_05_requiredspace3=Verf�gbarer Platz:
MSG_05_floppyseemsboot=Achtung: diese Diskette k�nnte die BOOT_DISK sein!
MSG_05_exchangefloppy=Diskette auswechseln und OK klicken um weiter zu gehen
MSG_05_floppynotformatted1=Diskette ist nicht formatiert!
MSG_05_floppynotformatted2=Formatieren?
MSG_05_formatfloppy=Diskette formatieren ...

[mkiso]
MSG_06_createisoimage=Erzeugen des fli4l-ISO-Images ...
MSG_06_buildisoimage=Erzeuge das ISO-Image '
MSG_06_finish1=Erzeugung des fli4l-ISO-Images abgeschlossen.
MSG_06_finish2=Nach dem Brennen des Images auf eine CD, k�nnen Sie Ihren fli4l-Router mit dieser starten.

[mknetboot]
MSG_07_mld1=Das Erzeugen eines Netzwerkboot-Images ist im Moment
MSG_07_mld2=mit allen Versionen von Microsoft-Windows nicht m�glich!

[dlg_mkfli4l_conf]
MSG_08_btnabort=Abbruch Build-Prozess
MSG_08_btnbuild=Starte Build-Prozess
MSG_08_nobasetxt=Im neuen Verzeichnis existiert keine 'base.txt'
MSG_08_changedirconfig=Verzeichnis mit den fli4l Konfigurationsdateien
MSG_08_changedconfigdir1=�nderung des Config-Verzeichnisses
MSG_08_changedconfigdir2=Soll das gew�hlte Verzeichnis zuk�nftig als Standard verwendet werden?
MSG_08_changedirbuild=Verzeichnis f�r die erzeugten fli4l Dateien
MSG_08_dirconfiginfo1=Eine �nderung des 'Config-Dir' setzt alle Optionen auf die Werte, die in der dortigen 'mkfli4l.txt'
MSG_08_dirconfiginfo2=gesetzt wurden, bzw. als Kommandozeilenparameter �bergeben wurden.
MSG_08_savemkfli4lconf=Aktuelle Einstellungen in mkfli4l.txt speichern
MSG_08_savemkfli4ldone=Die Einstellungen wurden in der mkfli4l.txt gespeichert
MSG_08_savemkfli4lerror=Fehler beim Schreiben der mkfli4l.txt
MSG_08TT_btnconfigdir=�ndern des aktuellen Verezichnisses mit den Config-Dateien
MSG_08TT_btnbuilddir=�ndern des Verzeichnisses f�r die erzeugten fli4l-Dateien
MSG_08TT_verbose=Ausf�hrliche Ausgabe einschalten
MSG_08TT_filesonly=Nur Dateien erzeugen
MSG_08TT_drive=Diskettenlaufwerk f�r die fli4l-Diskette
MSG_08TT_floppy_normal=Normalen Modus f�r die Diskette
MSG_08TT_floppy_safe=Sicheren Modus f�r die Diskette
MSG_08TT_remoteupdate=Remotupdate-Funktion aktivieren
MSG_08TT_remotehostname=Hostname oder IP-Adresse f�r das Remoteupdate
MSG_08TT_remoteusername=Benutzername f�r das Remoteupdate
MSG_08TT_remotepathname=Zielverzeichniss f�r das Remoteupdate
MSG_08TT_remoteport=Port f�r das Remoteupdate
MSG_08TT_btn_sshfile=Datei mit dem ssh-Key
MSG_08TT_btn_sshfileclear=L�schen der Benutzung vom SSH-Key -> Username/Passwort

[mkhdinstall]
MSG_09_start=HD-Install auf dem gew�hlten Laufwerk
MSG_09_copysyslinux=Kopiere syslinux.cfg ...
MSG_09_copykernel=Kopiere kernel ...
MSG_09_copyrootfstgz=Kopiere rootfs.img ...
MSG_09_copyrootfsbz2=Kopiere rootfs.bz2 ...
MSG_09_copyrccfg=Kopiere rc.cfg ...
MSG_09_copyopttarbz2=Kopiere opt.img ...
MSG_09_writesystem=Schreibe System-Dateien ...
MSG_09_finish1=Abschlu� des HD-pre-installs
MSG_09_finish2=- nach den Wechsel der Disk in Ihren Router, k�nnen Sie diesen starten
MSG_09_cancel=Abbruch der HD-pre-installation durch Benutzer
MSG_09_error=Fehler beim Schreiben von Dateien (HD-pre-Installation)!

MSG_09_admin1=Sie haben keine Admin-Rechte - diese werden zum erstellen des bootbaren Datentr�gers ben�tigt
MSG_09_admin2=M�chten Sie 'syslinux' als Administrator ausf�hren?
MSG_09_ask_pass=Passwort f�r Administrator
MSG_09_pass=Passwort:
MSG_09_wrongfs1=Das Laufwerk
MSG_09_wrongfs2=hat kein FAT-Filessystem!
MSG_09_errorcopy=Fehler beim kopieren der Datei

[mkls120]
MSG_10_start=Install LS120-Konfiguration auf dem gew�hlten Laufwerk
MSG_10_copysyslinux=Kopiere syslinux.cfg ...
MSG_10_copykernel=Kopiere kernel ...
MSG_10_copyrootfstgz=Kopiere rootfs.img ...
MSG_10_copyrootfsbz2=Kopiere rootfs.bz2 ...
MSG_10_copyrccfg=Kopiere rc.cfg ...
MSG_10_copyopttarbz2=Kopiere opt.img ...
MSG_10_writesystem=Schreibe System-Dateien ...
MSG_10_finish1=Abschlu� der Installation auf LS120
MSG_10_finish2=- nach den Wechsel der LS120 in Ihren Router, k�nnen Sie diesen starten
MSG_10_cancel=Abbruch der Installation auf LS120 durch Benutzer
MSG_10_error=Fehler beim Schreiben von Dateien!
MSG_10_wrongfs1=Das Laufwerk
MSG_10_wrongfs2=hat kein FAT-Filessystem!
MSG_10_errorcopy=Fehler beim kopieren der Datei
