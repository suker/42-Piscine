#!/bin/bash
find . -name "*.sh" | xargs -I{} basename {} | sed 's/\.sh//'
