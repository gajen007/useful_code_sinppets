import React, { useEffect, useState } from "react";
import { useRouter } from 'next/router'
import Link from 'next/link';
import axios from "axios";
import { useDispatch } from 'react-redux'

export default function PageName() {
	const [dataContainer, fillData] = useState("");
	const router = useRouter()
	const dispatchWhenClicked = useDispatch();
    const fetchFunction = async () => {
        try {
        	await axios.get(URL).then(res => { fillData(res.data); });
        }
        catch (e) {
        	alert("Fetch Error"); console.log(e);
        }
    }

    useEffect(() => { fetchFunction(); }, []);

    const linkClicked=(dataID)=>{
    	router.push("path_to_single_data/"+dataID);
    }
    
    return <ol>
    	{
    		dataContainer.map((data) => {
    			return (<li><Link onClick={linkClicked(data.id)} >{data.objFieldName}</Link></li>);
    		})
        }
    </ol>
}
