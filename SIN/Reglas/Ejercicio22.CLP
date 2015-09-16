;Ejercicio22

(deffacts hechos
	(vector v1 3 4 5 6 7 2 4 4 1)
	(vector v2 3 4 5 6 6 5 4 3)
	(vector v3 3 4 5 4 3)
	(vector v4 3 4 5 3 4 3)
)

(defrule creaAux
	(vector ?v $?valores)
=>
	(assert(aux ?v $?valores))
)

(defrule acorta
	?a<-(aux ?v ?x&:(numberp ?x) $?valores ?y&:(numberp ?y))
	(aux ?v $?medio)
	(test (= ?x ?y))
	(test(> (length$ $?medio) 1))
=>
	(retract ?a)
	(assert(aux ?v $?valores))
)

(defrule eliminaNoSim
	?a<-(aux ?v ?x&:(numberp ?x) $?valores ?y&:(numberp ?y))
	(not(test (= ?x ?y)))
=>
	(retract ?a)
	(printout t "El vector " ?v " no es simetrico" crlf)
)

(defrule esSimetricoImpar
	?a<-(aux ?v $?valores)
	(test(= (length$ $?valores) 1))
=>
	(retract ?a);Borra el aux una vez termina
	(printout t "El vector " ?v " es simetrico impar" crlf)
)

(defrule esSimetricoPar
	?a<-(aux ?v $?valores)
	(test(= (length$ $?valores) 0))
=>
	(retract ?a);Borra el aux una vez termina
	(printout t "El vector " ?v " es simetrico par" crlf)
)