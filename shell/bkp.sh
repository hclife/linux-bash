#!/bin/bash
# This script makes a backup of my home directory.

# Change the values of variables to make script work for you.
BACKUPDIR=/home
BACKUPFILES=franky
TARFILE=/var/tmp/home_franky.tar
BZIPFILE=/var/tmp/home_franky.tar.bz2
SERVER=bordeaux
REMOTEDIR=/opt/backup/franky
LOGFILE=/home/franky/log/home_backup.log

cd $BACKUPDIR
# This creates the archive
# tar cf /var/tmp/home_larkin.tar larkin > /dev/null 2>&1
tar cf $TARFILE $BACKUPFILES > /dev/null 2>&1

# First remove the old bzip2 file. 
# Redirect errors because this generates some if the archive doesnot exist.
# Then create a new compressed files.
# rm /var/tmp/home_larkin.tar.bz2 2> /dev/null
# bzip2 /var/home/home_larkin.tar
rm $BZIPFILE 2> /dev/null
bzip2 $TARFILE

# Copy the file to another host - 
# we have ssh keys for making this work without intervention.
# scp /var/tmp/home_larkin.tar.bz2 bordeaux:/opt/backup/larkin > /dev/null 2>&1
scp $BZIPFILE $SERVER:$REMOTEDIR > /dev/null 2>&1

# Create a timestamp in a logfile.
# date >> /home/larkin/log/home_larkin.log
# echo "Backup succeeded." >> /home/larkin/log/home_larkin.log
date >> $LOGFILE
echo backup suceeded >> $LOGFILE
