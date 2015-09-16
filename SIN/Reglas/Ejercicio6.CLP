;Ejercicio6

(deffacts vectores
	(vector v1 2 3 1 2 3 4 5)
	(vector v2 4 2 1 5 3)
	(vector v3 2 1 3 5 4)
	(vector v4 3 5 6 4)
)

(defrule tiene3y4
	(vector ?v $? ?x&:(numberp ?x) $?medio ?y&:(numberp ?x) $?)
	(test(= 1 (mod (length$ $?medio) 2)))
	(test (or
	(and (= ?x 3)(= ?y 4))
	(and (= ?y 3)(= ?x 4))
	))
=>
	(printout t "El vector " ?v " cumple la regla" crlf)
)