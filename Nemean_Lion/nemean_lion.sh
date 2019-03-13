#!/bin/bash

#su - access root and make it possible to overwrite sshd_config file
cat /etc/ssh/sshd_config | sed 's/#Port 22/Port 32942/' > .temp
mv .temp /etc/ssh/sshd_config
service ssh restart
#ls -l check the current port connected

