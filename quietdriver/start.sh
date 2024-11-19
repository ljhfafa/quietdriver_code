#!/bin/bash

echo "=========================="
echo "Starting App quietdriver for {APP_NAME_PRETTY}"


systemctl start quietdriver
systemctl start rosnodeChecker
