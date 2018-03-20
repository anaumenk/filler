# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visualizer.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 17:23:51 by anaumenk          #+#    #+#              #
#    Updated: 2018/03/20 17:23:56 by anaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

yellovO=$(printf "\033[33mO\033[32m")
yellovo=$(printf "\033[33mo\033[32m")
blueX=$(printf "\033[34mX\033[32m")
bluex=$(printf "\033[34mx\033[32m")
green=$(printf "\033[32m#")
piece=$(printf "\033[36mPiece")
got=$(printf "\033[32m<")

sed "s|#|$green|g" |
sed "s|Piece|$piece|g" |
sed "s|<|$got|g" |
sed "s|O|$yellovO|g" |
sed "/^0.. /s|o|$yellovo|g" |
sed "s|X|$blueX|g" |
sed "/^0.. /s|x|$bluex|g" |
sed "s|fin|player|g" 