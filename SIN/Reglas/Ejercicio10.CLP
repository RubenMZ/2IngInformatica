;Ejercicio10
(deffacts ejer10 (vector v1 3 4 2 6)(vector v2 43 2 54 3 7))

(defrule ordenaVector 
?h<-(vector ?nombre
$?cabeza
?x&:(numberp ?x)
?y&:(< ?y ?x)
$?cola)
=>
(retract ?h)
(assert (vector ?nombre $?cabeza ?y ?x $?cola))
)