echo "echo '$(cat bash-script.sh | gzip | base64 )' | base64 -d | gzip -d | bash" > payload.sh