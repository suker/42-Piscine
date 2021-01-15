#!/bin/bash
find . | wc -l | egrep -o '[0-9]+'
