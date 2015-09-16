(deffacts ejer7 (vector rojo 2 3 casa 1 )(vector jajaja 2 fdfsdfd jaja 123))

(defrule eliminaNoNum 
?h<-(vector $?x
?y&~:(numberp ?y)
$?z)
=>
(retract ?h)
(assert (vector $?x $?z))
(printout t "Elimino y: " ?y " conservo cabeza : " $?x " y cola: " $?z crlf)
)