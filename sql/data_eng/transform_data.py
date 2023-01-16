# This gets the metoffice historical temperature data and puts it in a SQL DB
# The data comes from https://www.metoffice.gov.uk/hadobs/hadcet/data/meantemp_daily_totals.txt

import pandas as pd


def main():
    source_filename = "data_eng/meantemp_daily_totals.txt"

    with open(source_filename, "r") as fp:
        # I happen to know that the first two rows are junk in my case
        raw_text_data = fp.readlines()[2:]
        temp_data = [
            tuple(e for e in row.strip().split(" ") if e)
            for row in raw_text_data
        ]

    # Now turn the temp data into a dataframe
    temp_df = pd.DataFrame(
        temp_data,
        columns=["Date", "Temperature"]
    )

    print(temp_df)
    print(temp_df.shape)

    # Now get into a SQL DB...




if __name__ == "__main__":
    main()
