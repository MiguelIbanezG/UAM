#!/bin/bash
for i in P1-base-ex; do
cd $i
ant replegar; ant delete-pool-local
cd -

done
cd P1-base-ex
ant unsetup-db
cd -

for i in P1-base-ex; do
cd $i
ant limpiar-todo todo
cd -
done
