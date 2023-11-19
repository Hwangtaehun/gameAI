;; problem file: red-prob7.pddl

(define (problem red-prob1)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf huntsman wine flower cakes)
    (:init (alive red) (alive granny) (alive wolf) (alive huntsman)
           (at red home) (like red flower) (errand red)
           (at wolf woods) (path_know wolf) (stop wolf) (foodchain wolf red) (foodchain wolf granny)
           (at granny grannyhouse) (like granny cakes) (path_know granny) (timing granny)
           (at huntsman grannyhouse) (like huntsman cakes) (path_know huntsman)
           (forward home woods) (forward woods grannyhouse))  
    (:goal (and (have red flower) (at wolf grannyhouse) (happy huntsman))))