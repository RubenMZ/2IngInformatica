;Ejercicio12
(deffacts ejer12 (dato 5)(dato 3)(dato 1)(dato 7)(dato 4))

(defrule insertaOrden
?d<-(dato ?x&:(numberp ?x))
(not (dato ?y&:(< ?y ?x)))

=>
(retract ?d)
(printout t "Variable dato: " ?x crlf)
)