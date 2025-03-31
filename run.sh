#!/bin/bash
cd build/executable/apps/Home

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/thaivodinh/Qt/6.5.3/gcc_64/lib

exec ./Home -c am-config.yaml
