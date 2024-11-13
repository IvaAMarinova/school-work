import StarRating from "./star-rating";

interface ProductCardProps {
    badge?: string;
    award?: string;
    image: string;
    usage: string;
    name: string;
    description: string;
    reviews: number;
    rating: number;
    price1?: string;
    price2?: string;
}

function ProductTwoSizesCard({
    badge,
    award,
    image,
    usage,
    name,
    description,
    reviews,
    rating,
    price1,
    price2
}: ProductCardProps) {
    return (
        <div className="max-w-xs mx-auto items-center p-6 rounded-lg">
            <div className="flex flex-col items-center relative">
                <div className="flex flex-col items-start absolute top-0 left-0">
                    {award && (
                        <img
                            src={award}
                            alt="Award"
                            className="w-14 h-auto mb-2 object-contain"
                        />
                    )}
                    {badge === "IMPROVED FORMULA" && (
                        <span className="bg-[#debaa7] text-xs text-white font-bold px-2 py-1 rounded-md mb-2">
                            IMPROVED <br /> FORMULA
                        </span>
                    )}
                    {badge === "NEW" && (
                        <span className="bg-[#debaa7] text-xs text-white font-bold px-2 py-1 rounded-md mb-2">
                            NEW
                        </span>
                    )}
                </div>

                <img
                    src={image}
                    alt={name}
                    className="h-60 object-contain"
                />
            </div>

            <h3 className="text-2xl text-center mt-4 text-[#816c65]">{usage}</h3>
            <h2 className="text-lg text-center text-[#816c65]">{name}</h2>
            <StarRating rating={rating} reviews={reviews} />
            <p className="text-center text-[#816c65] text-sm mb-4">{description}</p>

            <div className="flex flex-row items-center justify-center gap-4 mt-4">
                <div className="flex flex-col items-center">
                    <span className="text-md text-[#816c65] mb-1">{price1} лв. / 110ML</span>
                    <div className="w-32 py-2 bg-[#816c65] text-center text-white cursor-pointer hover:bg-[#daa48a]">
                        Добави
                    </div>
                </div>
                <div className="flex flex-col items-center">
                    <span className="text-md text-[#816c65] mb-1">{price2} лв. / 200ML</span>
                    <div className="w-32 py-2 bg-[#816c65] text-center text-white cursor-pointer hover:bg-[#daa48a]">
                        Добави
                    </div>
                </div>
            </div>
        </div>
    );
}

export default ProductTwoSizesCard;
