
  /**
 * @brief Concatenates two queues by adding all the elements in the second queue
 * to the first one. Upon successful exit the first queue will contain the 
 * elements from both queues and the second queue will be empty. In case of 
 * error the two queues will be unchanged.
 *
 * Example:
 *
 * Before concatenation: qa = [1, 2, 3, 4, 5, 6]
 *                       qb = [1, 2, 3, 4]
 *
 * After concatenation:  qa = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4]
 *                       qb = []
 *
 * @param qa, pointer to the first queue.
 * @param qb, pointer to the second queue.
 *
 * @return OK on success, ERROR if there is any error. In case of error the 
 * contents of both queues must remain unchanged.
 **/
  Status concatenate(Queue * qa, Queue * qb)
  {
    int i, tam;

    if ((qb == NULL) || (qa == NULL) || ((queue_size (qb) + queue_size (qa)) > 10)) /*Control de errores*/
    {
      return ERROR;
    }
    
    
    tam = queue_size (qa) + queue_size (qb);
    
    for (i = 0; i < tam; i++) /*Se pasarán los elementos de la cadena b a la a*/
    {
      queue_push (qa, queue_pop (qb));
    }

    return OK;
  }
