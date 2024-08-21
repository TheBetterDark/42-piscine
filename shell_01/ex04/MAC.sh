#!/bin/sh
ifconfig | grep -Eo '([0-9a-f]{2}:){5}[0-9a-f]{2}'
