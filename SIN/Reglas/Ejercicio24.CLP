;Ejercicio24
;Es el ejercicio 22 modificado

(deffacts hechos
	(vector v1 3 4 5 6 7 2 4 4 1)
	(vector v2 3 4 5 6 6 5 4 3)
	(vector v3 3 4 5 4 3)
	(vector v4 3 4 5 3 4 3)
)

(defrule esSimetrico
	(vector ?v $?valores)
	(forall (vector ?v $?ca ?x&:(numberp ?x) $?medio ?y&:(numberp ?y) $?co&:(eq (length$ $?ca) (length$ $?co)) )
		(test(eq ?x ?y))
	)
=>
	(printout t "El vector " ?v " es simetrico" crlf)
)