(deffacts ejer14 (factorial 3))

(deftemplate auxFact
(slot pedido )
(slot acc (default 1))
(slot contador (default 0))
)

(defrule contAux
?d<-(auxFact (pedido ?x&:(numberp ?x))(contador ?c&:(< ?c ?x)) (acc ?z) )
=>
(retract ?d)
(assert (auxFact (pedido ?x) (contador (+ ?c 1)) (acc (* ?z (+ ?c 1))) ))
)

(defrule crearFactorial
(and (factorial ?x) (not (auxFact (pedido ?x)) ) )
=>
(assert (auxFact (pedido ?x)))
)

(defrule terminar
(auxFact (pedido ?x)(contador ?y)(acc ?z))
(eq ?x ?y)
=>
(printout t "El factorial de " ?x " es " ?z crlf)
)