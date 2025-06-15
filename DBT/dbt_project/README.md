# Create related Conda vitural env for the DBT projects


## Environment Setup

> Conda CMD, need to create a new envornment to do the seperation
 
```
# step 1 
mkdir dbt_project && cd dbt_project && conda create -n dbt_env python=3.9

# step 2
conda activate dbt_env


# dbt 核心包：
pip install dbt-core
pip install dbt-snowflake
pip install dbt-bigquery
pip install dbt-postgres

```