;Devuelve la longitud del multicampo -> 6
(length$ (create$ 1 2 3 4 5 6))
;Devuelve el elemento de la 3 posicion -> 8
(nth$ 3 (create$ 1 2 8 4 5 6))
;Devuelve la cadena cortada entre el 2 y 5 elemento -> (f g s f)
(subseq$ (create$ s f g s f g h s f d) 2 5)
;Devuelve true si la cadena (todos los valores) 1 se ha encontrado en la segunda -> TRUE
(subsetp (create$ 1 3 8)(create$ a 2 8 f 3 1))
; FALSE
(subsetp (create$ a 2 8 f 3 1)(create$ 1 3 8))

;Imprime el primer elemento
(first$ (create$ 1 3 4 5))
;Imprime todo menos el primer elemento
(rest$ (create$ 1 3 4 5))
;Imprime la cadena
(explode$ "Hola, como estas")
;Imprime el multicampo
(implode$ (create$ 1 2 3 4))

;Devuelve un multicampo insertando el valor en la posicion x del multicampo
(insert$)


;Division normal con decimales si los tiene
(/ 3 2)
;Division entera sin decimales
(div 3 2)

;A una variable se le asigna el valor de la expresion
(bind ?x (create$ 1 2 3 ))
(printout t ?x)
