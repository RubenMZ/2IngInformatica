(deffacts ejer21 (datos 1 23 4 5 43)(datos 2 3 43 2)(datos 5))

(defrule imprimeMedianaImpar
(datos $?ca ?x $?co&:(eq (length $?ca)(length $?co)))
=>
(printout t "La mediana es " ?x crlf)
)

(defrule imprimeMedianaPar
(datos $?ca ?x ?y $?co&:(eq (length $?ca)(length $?co)))
=>
(printout t "La media es " (/ (+ ?x ?y) 2) crlf)
)