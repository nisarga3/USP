#!/bin/sh
#code to extract first name frm data recird
datarecord="lst=Clifford,first=Johnny Boy,State=CA"
comma1=`expr index "$datarecord" ","`
chopfield=${datarecord:$comma1}
comma2=`expr index "$chopfield" ","`
length=`expr $comma2-6-1`
firstname=${chopfield:6:$length}
echo $firstname
